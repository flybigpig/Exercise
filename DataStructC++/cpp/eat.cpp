#include <iostream>
#include <conio.h>
#include <windows.h>
#include <deque>
#include <ctime>
using namespace std;

// 定义地图大小
const int MAP_WIDTH = 40;
const int MAP_HEIGHT = 20;

// 定义方向
enum Direction {
    UP,
    DOWN, 
    LEFT,
    RIGHT
};

// 定义坐标结构
struct Position {
    int x;
    int y;
    Position(int x = 0, int y = 0): x(x), y(y) {}
};

class Snake {
private:
    deque<Position> body;  // 蛇身
    Direction direction;   // 移动方向
    Position food;        // 食物位置
    bool isAlive;        // 蛇是否存活
    int score;           // 得分

    // 生成新的食物
    void generateFood() {
        srand(time(0));
        while (true) {
            Position newFood(rand() % (MAP_WIDTH-2) + 1, 
                           rand() % (MAP_HEIGHT-2) + 1);
            bool overlap = false;
            
            // 检查是否与蛇身重叠
            for (const Position& pos : body) {
                if (pos.x == newFood.x && pos.y == newFood.y) {
                    overlap = true;
                    break;
                }
            }
            
            if (!overlap) {
                food = newFood;
                break;
            }
        }
    }

public:
    Snake() {
        // 初始化蛇身
        body.push_back(Position(MAP_WIDTH/2, MAP_HEIGHT/2));
        direction = RIGHT;
        isAlive = true;
        score = 0;
        generateFood();
    }

    // 移动蛇
    void move() {
        Position newHead = body.front();
        
        // 根据方向移动蛇头
        switch(direction) {
            case UP:    newHead.y--; break;
            case DOWN:  newHead.y++; break;
            case LEFT:  newHead.x--; break;
            case RIGHT: newHead.x++; break;
        }

        // 检查是否撞墙
        if (newHead.x <= 0 || newHead.x >= MAP_WIDTH-1 || 
            newHead.y <= 0 || newHead.y >= MAP_HEIGHT-1) {
            isAlive = false;
            return;
        }

        // 检查是否撞到自己
        for (const Position& pos : body) {
            if (newHead.x == pos.x && newHead.y == pos.y) {
                isAlive = false;
                return;
            }
        }

        body.push_front(newHead);

        // 检查是否吃到食物
        if (newHead.x == food.x && newHead.y == food.y) {
            score += 10;
            generateFood();
        } else {
            body.pop_back();
        }
    }

    // 改变方向
    void changeDirection(Direction newDir) {
        // 防止180度转向
        if ((direction == UP && newDir == DOWN) ||
            (direction == DOWN && newDir == UP) ||
            (direction == LEFT && newDir == RIGHT) ||
            (direction == RIGHT && newDir == LEFT)) {
            return;
        }
        direction = newDir;
    }

    // 绘制游戏画面
    void draw() {
        system("cls");  // 清屏

        // 绘制上边界
        for (int i = 0; i < MAP_WIDTH; i++)
            cout << "#";
        cout << endl;

        // 绘制游戏区域
        for (int y = 1; y < MAP_HEIGHT-1; y++) {
            cout << "#";  // 左边界
            for (int x = 1; x < MAP_WIDTH-1; x++) {
                bool isBodyPart = false;
                for (const Position& pos : body) {
                    if (pos.x == x && pos.y == y) {
                        cout << "O";
                        isBodyPart = true;
                        break;
                    }
                }
                if (!isBodyPart) {
                    if (food.x == x && food.y == y)
                        cout << "*";
                    else
                        cout << " ";
                }
            }
            cout << "#" << endl;  // 右边界
        }

        // 绘制下边界
        for (int i = 0; i < MAP_WIDTH; i++)
            cout << "#";
        cout << endl;

        // 显示得分
        cout << "Score: " << score << endl;
    }

    bool alive() const { return isAlive; }
};

int main() {
    Snake snake;
    while (snake.alive()) {
        snake.draw();
        Sleep(100);  // 控制游戏速度

        // 处理键盘输入
        if (_kbhit()) {
            char key = _getch();
            switch(key) {
                case 'w': snake.changeDirection(UP); break;
                case 's': snake.changeDirection(DOWN); break;
                case 'a': snake.changeDirection(LEFT); break;
                case 'd': snake.changeDirection(RIGHT); break;
            }
        }

        snake.move();
    }

    system("cls");
    cout << "Game Over!" << endl;
    return 0;
}
