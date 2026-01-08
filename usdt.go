package main

import (
	"encoding/json"
	"fmt"
	"io/ioutil"
	"log"
	"net/http"
	"net/url"
)

// Struct untuk memetakan data respons dari API
type Transaction struct {
	Hash      string `json:"hash"`
	From      string `json:"from"`
	To        string `json:"to"`
	Amount    string `json:"amount"`
	Timestamp string `json:"timestamp"`
}

func getTransactionData(address, apiKey string) {
	// URL API TokenView
	apiURL := "https://api.tokenview.io/v1/transaction/USDT"

	// Membangun URL dengan query string
	url := fmt.Sprintf("%s?address=%s&api_key=%s", apiURL, address, apiKey)

	// Mengirim permintaan GET ke API
	resp, err := http.Get(url)
	if err != nil {
		log.Fatal("Error fetching data: ", err)
	}
	defer resp.Body.Close()

	// Membaca respons
	body, _ := ioutil.ReadAll(resp.Body)

	// Parsing JSON
	var result []Transaction
	err = json.Unmarshal(body, &result)
	if err != nil {
		log.Fatal("Error parsing JSON: ", err)
	}

	// Menampilkan data transaksi
	for _, transaction := range result {
		fmt.Println("Transaction Hash:", transaction.Hash)
		fmt.Println("From:", transaction.From)
		fmt.Println("To:", transaction.To)
		fmt.Println("Amount:", transaction.Amount)
		fmt.Println("Timestamp:", transaction.Timestamp)
	}
}

func main() {
	// Masukkan alamat dan API Key
	address := "TRGSNhnQ9d6PwqB5Kd9NsRvXGYgbNRfnHP" // Ganti dengan alamat wallet
	apiKey := "YOUR_API_KEY" // Ganti dengan API key yang valid

	// Ambil data transaksi
	getTransactionData(address, apiKey)
}
