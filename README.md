# lab1 - chuyên đề thiết kế hệ thống nhúng 1.

### Hiệu ứng
Hiệu ứng 2 và hiệu ứng 3 có 12 phase (từ phase 0 đến phase 11): mỗi led chớp tắt trong 4 phase. 1 phase tương đương với 1 chu kì mà ta có thể thay đổi bằng nút nhấn (100ms -> 2s).

### Cấu hình timer
![Công thức tính](/Images/16cap1.png)  
internal clock = 72Mhz.

Chu kì của timer3 là 100ms. Vậy ta chọn ra được prescaler = 7200-1 và counter period = 1000-1.
Sử dụng timer3 để làm chu kì chớp tắt leds.

Chu kì của timer4 là 10ms. Vậy ta chọn ra được prescaler = 7200-1 và counter period = 100-1.

### Nút nhấn
Thay đổi chu kì của timer trực tiếp bằng cách set thanh ghi ARR của timer3(auto-reload register).

Sử dụng timer4 để check buttons.
Phát hiện cạch của nút nhấn(sự nhấn nhả) bằng cách kiểm tra trạng thái của nút nhấn ở chu kì hiện tại và chu kì trước đó. Nếu chu kì trước trạng thái là GPIO_PIN_SET và chu kì hiện tại là GPIO_PIN_RESET thì nút nhấn vừa được thả ra. 