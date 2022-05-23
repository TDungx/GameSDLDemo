Báo cáo cho GameSDLDemo
  I. Cách cài đặt:
    1. Tải các file qua link github.
    2. Các câu lệnh trong các file cpp và file header.
    3. Cần cài đặt SDL2, SDL_image, các file dll trong github, các phần mềm và thư viện để chạy code cpp.
  II. Mô tả chung về game:
    1. Đây là game bắn máy bay.
    2. Ta sẽ di chuyển xe tăng qua các nút di chuyển trái phải lên xuống.
    3. Bắn đạn qua các phím nhấn chuột
        -Chuột trái là đạn thường
        -Đạn trái là lazer
    4.Máy bay có thể nhả đạn( khi nào mình bắn đạn thì máy bay cũng nhả đạn để tránh TH spam đạn)
  III. Các chức năng 
     -Di chuyển  qua các nút
     -Bắn đạn qua chuột
     -Menu đầu và kết quả cuốt game
     -Link video https://drive.google.com/file/d/1FlamR9HbHbGIN7robUX4GSso3OHCz_vW/view?usp=sharing
  IV. Các kĩ thuật 
     -Mảng: đạn, máy bay,...
     -Con trỏ
     -Lớp: baseObject, bulletObject
     -Đồ họa: thư viện SDL, SDL_image
  V. Kết luận
      -Game có đồ họa và có thể chơi được
      -Hướng phát triển: 
        +Thêm các chức năng của xe tăng 
          .Tạo ra xe tăng con hỗ trợ
          .Sau một thời gian khi bấm nút Power tạo ra vụ nổ xóa toàn bộ máy bay trên màn hình
          .Tạo thêm bổ trợ: Hồi máu, tạo thêm khiên
          .Thêm tiền và shop để mua bổ trợ
        +Chia các loại đạn
        +Thêm loại máy bay( BOSS )
      -Điều tâm đấc:
        +Biết thêm cách đọc đồ họa.
        Gặp những bug đầu tiên và tìm được các fix bug.
