# lab1_chuyen_de
lab1 - chuyên đề thiết kế hệ thống nhúng 1.

hiệu ứng 2 và hiệu ứng 3 có 9 phase (từ phase 0 đến phase 8, chọn 9 vì chia lấy dư và lấy nguyên cho 3 đều thuộc khoảng 0 -> 2 : được 3 giá trị đủ cho 3 led): mỗi led chớp tắt trong 3 phase. 1 phase tương đương với 1 chu kì mà ta có thể thay đổi bằng nút nhấn (100ms -> 2s).

sử dụng timer3 để tạo ra unit cycle (100ms). đếm số unit cycle để tạo thành 1 cycle. Ví dụ cycle = 1.5s => sau mỗi 15 unit cycle ta được 1 cycle chính (để nháy led).

sử dụng timer4 để check buttons.