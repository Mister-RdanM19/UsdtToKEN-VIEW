<?php

// URL API TokenView
$api_url = "https://api.tokenview.io/v1/transaction/USDT";  // Pastikan API URL yang benar

// Alamat wallet atau ID transaksi yang akan dicari
$address = "TRGSNhnQ9d6PwqB5Kd9NsRvXGYgbNRfnHP";  // Ganti dengan alamat wallet yang relevan

// Siapkan parameter API
$params = array(
    "address" => $address,
    "api_key" => "YOUR_API_KEY"  // Ganti dengan API key jika diperlukan
);

// Siapkan URL untuk permintaan API
$url = $api_url . "?" . http_build_query($params);

// Inisialisasi cURL
$ch = curl_init();

// Set opsi cURL untuk permintaan GET
curl_setopt($ch, CURLOPT_URL, $url);
curl_setopt($ch, CURLOPT_RETURNTRANSFER, 1);

// Eksekusi permintaan cURL
$response = curl_exec($ch);

// Cek jika ada kesalahan cURL
if (curl_errno($ch)) {
    echo "Error: " . curl_error($ch);
} else {
    // Tampilkan hasil respons API
    $data = json_decode($response, true);
    echo "Transaction Data: <pre>";
    print_r($data);
    echo "</pre>";
}

// Tutup koneksi cURL
curl_close($ch);

?>
