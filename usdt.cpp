#include <iostream>
#include <string>
#include <curl/curl.h>
#include <json/json.h>

// Callback function untuk libcurl
size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp) {
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

void getTransactionData(const std::string& address, const std::string& apiKey) {
    CURL *curl;
    CURLcode res;
    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();
    if(curl) {
        std::string url = "https://api.tokenview.io/v1/transaction/USDT?address=" + address + "&api_key=" + apiKey;
        std::string response_string;

        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response_string);

        res = curl_easy_perform(curl);
        if(res != CURLE_OK)
            std::cerr << "cURL failed: " << curl_easy_strerror(res) << std::endl;

        Json::Reader reader;
        Json::Value root;
        if (reader.parse(response_string, root)) {
            const Json::Value transactions = root["transactions"];
            for (const auto& txn : transactions) {
                std::cout << "Transaction Hash: " << txn["hash"].asString() << std::endl;
                std::cout << "From: " << txn["from"].asString() << std::endl;
                std::cout << "To: " << txn["to"].asString() << std::endl;
                std::cout << "Amount: " << txn["amount"].asString() << std::endl;
                std::cout << "Timestamp: " << txn["timestamp"].asString() << std::endl;
            }
        }

        curl_easy_cleanup(curl);
    }
    curl_global_cleanup();
}

int main() {
    std::string address = "TRGSNhnQ9d6PwqB5Kd9NsRvXGYgbNRfnHP";  // Ganti dengan alamat wallet yang relevan
    std::string apiKey = "YOUR_API_KEY";  // Ganti dengan API key yang valid
    getTransactionData(address, apiKey);
    return 0;
}
