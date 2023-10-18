# lab1 - chuyên đề thiết kế hệ thống nhúng 1.

### Hiệu ứng
Hiệu ứng 2 và hiệu ứng 3 có 12 phase (từ phase 0 đến phase 11): mỗi led chớp tắt trong 4 phase. 1 phase tương đương với 1 chu kì mà ta có thể thay đổi bằng nút nhấn (100ms -> 2s).

### Cấu hình timer
![Công thức tính](/Images/16cap1.png)  
System clock = 72Mhz.

Chu kì của timer3 là 100ms. Vậy ta chọn ra được prescaler = 7200-1 và counter period = 1000-1.
Sử dụng timer3 để làm chu kì chớp tắt leds.

Chu kì của timer4 là 6553.5ms.

### Nút nhấn
Kiểm tra trạng thái của nút nhấn liên tục trong loop(1) để quét được với tần số tối đa (thay vì quét theo chu kì cố định của timer).
Phát hiện cạch của nút nhấn (sự nhấn nhả) bằng cách kiểm tra trạng thái của nút nhấn ở chu kì hiện tại và chu kì trước đó. Nếu chu kì trước trạng thái là GPIO_PIN_SET và chu kì hiện tại là GPIO_PIN_RESET thì nút nhấn vừa được thả ra. 
- Cách tính holdTime: hàm __HAL_TIM_SET_COUNTER trả về giá trị counter của timer. Tính toán giá trị chênh lệch giữa lúc thả nút và lúc bắt đầu nhấn nút, ta có được thời gian nhấn giữ.

Thay đổi chu kì của chớp tắt led trực tiếp bằng cách update thanh ghi ARR của timer3 (auto-reload register).