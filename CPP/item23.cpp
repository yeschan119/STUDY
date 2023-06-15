#include <iostream>
// 멤버함수 보는 비멤버 비프렌드 함수 사용
// 비멤버 함수를 사용하면 좋은점
// 캡슐화 정도가 높고, 패키징 유연성이 커지고, 기능적인 확정성도 높음.
// 위 내용은 비프렌드 함수에만 적용
// 비프렌드 함수는 캠슐화에 영향을 끼칠 것이기 때문.
// namespace 사용하면 확장성이 높아짐

namespace WebBrowser {
    class Web {
        private:
            int a = 0;
        public:
            void print_web() {
                std::cout << "WebBrowser" << std::endl;
            }
    };

    void clearBrowser (Web &web) {
        std::cout << "clear browser" << std::endl;
    }
}
int main () {
    
}