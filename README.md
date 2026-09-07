# Workshop ITS Robocon

Selamat datang di **Workshop ITS Robocon!**

Modul ini akan membahas tentang ROS2 serta cara mengimplementasikannya di bidang robotika.

## Apa itu ROS2 (Robot Operating System)?

ROS2 (Robot Operating System) adalah framework untuk mengembangkan software robotika. ROS2 memiliki empat fungsi utama yaitu:
1. **Komunikasi antar proses**: Dalam pembuatan sebuah robot pasti akan terjadi komunikasi antara perangkat-perangkatnya. Namun semakin rumit sebuah robot semakin banyak pula komunikasi yang terjadi, maka untuk mempermudah komunikasi tersebut ROS menawarkan solusi berupa beberapa protokol komunikasi yang dapat diterapkan, seperti publisher-subscriber, service, dan action. Dan untuk semakin mempermudah pengembangan robotika ROS juga menyediakan aplikasi untuk memvisualisasikan komunikasi-komunikasi yang terjadi.
![Visualisasi komunikasi di ros](assets/Topic-SinglePublisherandSingleSubscriber.gif)
2. **Package management**: Sebelum adanya ROS, pengembangan perangkat lunak untuk robot seringkali bersifat sangat khusus dan tertutup. Setiap institusi cenderung mengembangkan library yang sangat spesifik untuk keperluan mereka, sehingga sulit untuk berbagi dan menggunakan kembali kode yang sudah ada. Hal ini menyebabkan setiap institusi untuk merombak, atau bahkan menulis ulang library yang sebenarnya sudah pernah dibuat. ROS hadir sebagai solusi dengan menyediakan kerangka kerja yang terstandarisasi. Dengan ROS, library perangkat lunak dapat dibagi dan digunakan secara lebih mudah, sehingga mempercepat pengembangan robot dan mendorong inovasi.
![ilustrasi ros package](assets/ros2_pkg.jpg)
3. **Simulasi**: ROS dapat digunakan dengan [RViZ2](https://docs.ros.org/en/humble/p/rviz2/doc/index.html), [Gazebo](https://gazebosim.org/home) atau [Webots](https://cyberbotics.com/) untuk mensimulasikan robot, mulai dari bagian terkecilnya sampai dengan pergerakannya di suatu latar tempat.
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
Node adalah sebuah program yang berjalan menggunakan ROS2, program yang memiliki satu atau beberapa tugas tertentu dalam sistem robot. Sebuah robot biasanya memiliki banyak tugas yang berbeda. Daripada membuat semuanya menjadi satu program besar, kita dapat memisahkannya menjadi beberapa node.

![Visualisasi node di ros](assets/Nodes-TopicandService.gif)

### Topic
Topic adalah jalur komunikasi yang digunakan node untuk mengirim dan menerima data.
![topic](assets/Topic-MultiplePublisherandMultipleSubscriber.gif)
Sebuah node dapat mengirimkan informasi ke saluran tertentu, dan node lain yang mendengarkan saluran tersebut dapat menerima informasi yang dikirimkan.

### Message
Message adalah format data yang dikirimkan melalui topic. Berikut adalah contoh dari format data yang dapat dikirim melalui ROS2:
- msg/Int32
- msg/UInt32
- msg/Float32
- msg/Bool
- msg/String
- msg/ColorRGBA

Semisal kita mau mengirim data dengan suatu format, tapi format tersebut tidak disediakan secara langsung oleh ROS2, kita dapat menentukan format kita sendiri menggunakan [custom interfaces](https://docs.ros.org/en/humble/Tutorials/Beginner-Client-Libraries/Single-Package-Define-And-Use-Interface.html).

## Persiapan sebelum Hands-On
TheConstruct.ai merupakan salah satu cara menjalankan ROS2 tanpa harus melakukan instalasi apapun.

### Membuat Akun di TheConstruct.ai
1. Masuk ke https://www.theconstruct.ai, lalu buat akun dan login.
2. Masuk ke https://app.theconstruct.ai, dan pilih opsi  "My Rosject", lalu pilih "Create a New Rosject"
![my rosject](assets/my_rosject.png)
3. Setup Rosject dengan opsi sebagai berikut:
![create new](assets/create_new.png)
4. Pilih Humble sebagai ROS version-nya:
![pilih humble](assets/pilih_humble.png)
5. Pilih "Empty Simulation" di Simulation Environment:
![empty simulation](assets/empty_sim.png)
6. Jika sudah selesai, kalian akan disambut dengan tampilan seperti ini:
![selesai](assets/done_setyp.png)