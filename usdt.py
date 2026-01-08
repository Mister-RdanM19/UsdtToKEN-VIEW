import requests

# URL API TokenView (contoh, pastikan kamu memiliki API key atau dokumentasi API yang sesuai)
api_url = "https://api.tokenview.io/v1/transaction/USDT"  # Ini hanya contoh, pastikan URL API yang benar

# Ganti dengan alamat wallet atau ID transaksi
address = "TRGSNhnQ9d6PwqB5Kd9NsRvXGYgbNRfnHP"  # Contoh alamat wallet

# Parameter untuk permintaan API (misalnya, mencari data transaksi atau saldo)
params = {
    "address": address,
    "api_key": "YOUR_API_KEY"  # Jika perlu API key
}

# Kirimkan permintaan GET ke API
response = requests.get(api_url, params=params)

# Periksa apakah permintaan berhasil
if response.status_code == 200:
    # Menampilkan data hasil respons
    data = response.json()
    print("Transaction Data:", data)
else:
    print(f"Error: {response.status_code}")
