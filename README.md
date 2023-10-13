# lab1_chuyen_de
lab1 - chuyên đề thiết kế hệ thống nhúng 1.

hiệu ứng 2 và hiệu ứng 3 có 12 phase (từ phase 0 đến phase 11): mỗi led chớp tắt trong 4 phase. 1 phase tương đương với 1 chu kì mà ta có thể thay đổi bằng nút nhấn (100ms -> 2s).

sử dụng timer3 để tạo ra unit cycle (100ms). đếm số unit cycle để tạo thành 1 cycle. Ví dụ cycle = 1.5s => sau mỗi 15 unit cycle ta được 1 cycle chính (để nháy led).

sử dụng timer4 để check buttons.
