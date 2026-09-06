# Workshop ITS Robocon

Selamat datang di **Workshop ITS Robocon!**

Modul ini akan membahas tentang ROS2 serta cara mengimplementasikannya di bidang robotika.

## Apa itu ROS2 (Robot Operating System)?

ROS2 (Robot Operating System) adalah framework untuk mengembangkan software robotika. ROS2 memiliki empat fungsi utama yaitu:
1. **Komunikasi antar proses**: Dalam pembuatan sebuah robot pasti akan terjadi komunikasi antara perangkat-perangkatnya. Namun semakin rumit sebuah robot semakin banyak pula komunikasi yang terjadi, maka untuk mempermudah komunikasi tersebut ROS menawarkan solusi berupa beberapa protokol komunikasi yang dapat diterapkan, seperti publisher-subscriber, service, dan action. Dan untuk semakin mempermudah pengembangan robotika ROS juga menyediakan aplikasi untuk memvisualisasikan komunikasi-komunikasi yang terjadi.
![Visualisasi komunikasi di ros](assets/Nodes-TopicandService.gif)
2. **Package management**: Sebelum adanya ROS, pengembangan perangkat lunak untuk robot seringkali bersifat sangat khusus dan tertutup. Setiap institusi cenderung mengembangkan library yang sangat spesifik untuk keperluan mereka, sehingga sulit untuk berbagi dan menggunakan kembali kode yang sudah ada. Hal ini menyebabkan setiap institusi untuk merombak, atau bahkan menulis ulang library yang sebenarnya sudah pernah dibuat. ROS hadir sebagai solusi dengan menyediakan kerangka kerja yang terstandarisasi. Dengan ROS, library perangkat lunak dapat dibagi dan digunakan secara lebih mudah, sehingga mempercepat pengembangan robot dan mendorong inovasi.
![ilustrasi ros package](assets/ros2_pkg.jpg)
3. **Hardware controller**: Seperti yang telah dijelaskan di atas ROS dan komunitasnya sudah menyediakan banyak library dan beberapa diantara digunakan untuk mengkontrol hardware dengan beberapa lapisan abstraksi untuk memudahkan penggunaannya.
4. **Simulasi**: ROS dapat digunakan dengan [RViZ2](https://docs.ros.org/en/humble/p/rviz2/doc/index.html), [Gazebo](https://gazebosim.org/home) atau [Webots](https://cyberbotics.com/) untuk mensimulasikan robot, mulai dari bagian terkecilnya sampai dengan pergerakannya di suatu latar tempat.
![simulasi](assets/ros_hardware.GIF)

## Konsep Dasar ROS2
Walau namanya *Operating System* ROS2 berbeda dengan *operating system* pada umumnya seperti Windows, Android, MacOS, dsb. ROS2 justru berjalan di atas OS

Karena ROS2 bukanlah OS, ROS2 tetap membutuhkan OS untuk menjalankan program-programnya.

Dalam praktiknya, ROS2 paling umum digunakan pada OS berbasis Linux, khususnya Ubuntu. Oleh karena itu, ketika mengikuti tutorial ROS2, kita akan sering menemukan perintah-perintah yang dijalankan melalui terminal Ubuntu.

Sebagai gambaran sederhana, lingkungan yang kita gunakan dapat dilihat sebagai beberapa lapisan:
![pyramid](assets/pyramid.png)
Jadi, ketika kita menjalankan sebuah program ROS2, sebenarnya kita menjalankan program biasa di dalam OS, tetapi program tersebut menggunakan library dan mekanisme yang disediakan oleh ROS2.

## Komponen ROS2
### Node
