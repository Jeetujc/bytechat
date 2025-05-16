
# 💬 ByteChat

ByteChat is a simple TCP-based server-client chat application written in C++. It allows basic message exchange over a network using sockets.

---

## ⚙️ Requirements

- Linux system (Tested on Ubuntu/Kubuntu)
- g++ compiler
- Two network-connected systems (same LAN recommended)

---

## 🔧 Installation and Usage

### Step 1: Clone the Repository

On both machines (server and client):

```bash
git clone https://github.com/yourusername/bytechat.git
cd bytechat
```

### Step 2: Compile the Code

On both the server and client machines, run:

```bash
g++ server.cpp -o server
g++ client.cpp -o client
```

This will generate two executables: `server` and `client`.

### ▶️ Step 3: Run the Server (Machine 1)

On one PC (preferably with a static or known local IP address), run the server:

```bash
./server
```

It will start listening on port **54000**.

### 💻 Step 4: Run the Client (Machine 2)

On another PC connected to the same network, run the client:

```bash
./client
```

You will be prompted to enter the **server's IP address** and **port (54000)**. Example:

```
enter server ip
192.168.1.10
enter a port
54000
```

You can now type messages to send to the server. The server will echo them back.

---

## 🔄 Communication Flow

1. Server listens for incoming TCP connections.
2. Client connects to the server using IP and port.
3. Messages sent by client are received and echoed by the server.
4. Connection remains open until either side closes it.

---

## 📌 Notes

- Make sure both machines are on the **same LAN** and can **ping each other**.
- Port **54000** must not be blocked by any firewall.
- The server must be started **before** the client.

---

## 🧠 License

This project is for learning purposes and is released under the MIT License.
