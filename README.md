# lab1 - chuyên đề thiết kế hệ thống nhúng 1.

###
[Link demo](https://drive.google.com/file/d/12ZkMeiDxIX1s6i0-gwFi5phEPDBhVhnq/view?usp=sharing).

### Hiệu ứng
Hiệu ứng 2 và hiệu ứng 3 có 12 phase (từ phase 0 đến phase 11): mỗi led chớp tắt trong 4 phase. 1 phase tương đương với 1 chu kì mà ta có thể thay đổi bằng nút nhấn (100ms -> 2s).
- Hiệu ứng 1: chớp tắt 3 led cùng lúc.
- Hiệu ứng 2: Chớp tắt lần lượt từng bóng theo thứ tự red, green, blue.
- Hiệu ứng 3: Chớp tắt lần lượt từng led, mỗi led 4 lần sau đó chuyển sang led khác.
### Cấu hình timer
![Công thức tính](/Images/16cap1.png)  
System clock = 72Mhz.

Chu kì của timer3 có thể được thay đổi bằng nút nhấn (ghi vào thanh ghi ARR), giá trị khởi tạo là 100ms. Vậy ta chọn ra được prescaler = 7200-1 và counter period = 1000-1.
Sử dụng timer3 để làm chu kì chớp tắt led.

Chu kì của timer4 là 10ms. Vậy ta chọn ra được prescaler = 7200-1 và counter period = 100-1.

### Nút nhấn
Thay đổi chu kì của chớp tắt led trực tiếp bằng cách update thanh ghi ARR của timer3 (auto-reload register).

Sử dụng timer4 để check buttons (kiểm tra trạng thái của nút nhấn).
Phát hiện cạch của nút nhấn (sự nhấn nhả) bằng cách kiểm tra trạng thái của nút nhấn ở chu kì hiện tại và chu kì trước đó. Nếu chu kì trước trạng thái là GPIO_PIN_SET và chu kì hiện tại là GPIO_PIN_RESET thì nút nhấn vừa được thả ra. 
### Hiển thị chu kì chớp/tắt led và hiệu ứng ra màn hình
Sử dụng UART1 với baud rate = 115200.

Gọi hàm display mỗi khi có thay đổi về chu kì hoặc hiệu ứng (do 2 button).