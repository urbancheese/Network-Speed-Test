#include <iostream>
#include <chrono>
#include <curl/curl.h>

size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp) {
    return size * nmemb;
}

void downloadTest(const std::string& url) {
    CURL* curl;
    CURLcode res;

    curl = curl_easy_init();
    if(curl) {
        auto start = std::chrono::high_resolution_clock::now();
        
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);

        res = curl_easy_perform(curl);

        if(res == CURLE_OK) {
            auto end = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> duration = end - start;
            
            double speed;
            curl_easy_getinfo(curl, CURLINFO_SIZE_DOWNLOAD, &speed);
            std::cout << "Download Time: " << duration.count() << " seconds" << std::endl;
        } else {
            std::cerr << "Error: " << curl_easy_strerror(res) << std::endl;
        }

        curl_easy_cleanup(curl);
    }
}

void pingTest(const std::string& url) {
    CURL* curl;
    CURLcode res;
    
    curl = curl_easy_init();
    if(curl) {
        auto start = std::chrono::high_resolution_clock::now();
        
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_NOBODY, 1L);

        res = curl_easy_perform(curl);

        if(res == CURLE_OK) {
            auto end = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> duration = end - start;

            std::cout << "Ping: " << duration.count() * 1000 << " ms" << std::endl;
        } else {
            std::cerr << "Error: " << curl_easy_strerror(res) << std::endl;
        }

        curl_easy_cleanup(curl);
    }
}

int main() {
    std::string testURL = "http://speedtest.ftp.otenet.gr/files/test1Gb.db";

    std::cout << "Running Network Speed Test..." << std::endl;
    
    pingTest(testURL);
    downloadTest(testURL);

    return 0;
}
