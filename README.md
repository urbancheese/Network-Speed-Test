# Network-Speed-Test

This C++ application utilizes the libcurl library to measure network speed, including both ping time and download speed. It provides a simple and effective way to assess your network's performance.

How to Use:

Compile:
Bash
g++ network_speed_test.cpp -o network_speed_test -lcurl
Use code with caution.

Run:
Bash
./network_speed_test
Use code with caution.

Functionality:

Ping Test: Measures the round-trip time (RTT) to a specified URL.
Download Test: Measures the download speed from a given URL.
Customization:

URL: Replace the hardcoded URL in the main function with your desired test URL.
Output Format: Customize the output format by modifying the printing statements within the pingTest and downloadTest functions.
Example Output:

Running Network Speed Test...

Ping: 25.34 ms
Download Time: 2.5 seconds
