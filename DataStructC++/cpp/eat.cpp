#include <iostream>
#include <conio.h>
#include <windows.h>
#include <deque>
#include <ctime>
using namespace std;

// �����ͼ��С
const int MAP_WIDTH = 40;
const int MAP_HEIGHT = 20;

// ���巽��
enum Direction {
    UP,
    DOWN, 
    LEFT,
    RIGHT
};

// ��������ṹ
struct Position {
    int x;
    int y;
    Position(int x = 0, int y = 0): x(x), y(y) {}
};

class Snake {
private:
    deque<Position> body;  // ����
    Direction direction;   // �ƶ�����
    Position food;        // ʳ��λ��
    bool isAlive;        // ���Ƿ���
    int score;           // �÷�

    // �����µ�ʳ��
    void generateFood() {
        srand(time(0));
        while (true) {
            Position newFood(rand() % (MAP_WIDTH-2) + 1, 
                           rand() % (MAP_HEIGHT-2) + 1);
            bool overlap = false;
            
            // ����Ƿ��������ص�
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
        // ��ʼ������
        body.push_back(Position(MAP_WIDTH/2, MAP_HEIGHT/2));
        direction = RIGHT;
        isAlive = true;
        score = 0;
        generateFood();
    }

    // �ƶ���
    void move() {
        Position newHead = body.front();
        
        // ���ݷ����ƶ���ͷ
        switch(direction) {
            case UP:    newHead.y--; break;
            case DOWN:  newHead.y++; break;
            case LEFT:  newHead.x--; break;
            case RIGHT: newHead.x++; break;
        }

        // ����Ƿ�ײǽ
        if (newHead.x <= 0 || newHead.x >= MAP_WIDTH-1 || 
            newHead.y <= 0 || newHead.y >= MAP_HEIGHT-1) {
            isAlive = false;
            return;
        }

        // ����Ƿ�ײ���Լ�
        for (const Position& pos : body) {
            if (newHead.x == pos.x && newHead.y == pos.y) {
                isAlive = false;
                return;
            }
        }

        body.push_front(newHead);

        // ����Ƿ�Ե�ʳ��
        if (newHead.x == food.x && newHead.y == food.y) {
            score += 10;
            generateFood();
        } else {
            body.pop_back();
        }
    }

    // �ı䷽��
    void changeDirection(Direction newDir) {
        // ��ֹ180��ת��
        if ((direction == UP && newDir == DOWN) ||
            (direction == DOWN && newDir == UP) ||
            (direction == LEFT && newDir == RIGHT) ||
            (direction == RIGHT && newDir == LEFT)) {
            return;
        }
        direction = newDir;
    }

    // ������Ϸ����
    void draw() {
        system("cls");  // ����

        // �����ϱ߽�
        for (int i = 0; i < MAP_WIDTH; i++)
            cout << "#";
        cout << endl;

        // ������Ϸ����
        for (int y = 1; y < MAP_HEIGHT-1; y++) {
            cout << "#";  // ��߽�
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
            cout << "#" << endl;  // �ұ߽�
        }

        // �����±߽�
        for (int i = 0; i < MAP_WIDTH; i++)
            cout << "#";
        cout << endl;

        // ��ʾ�÷�
        cout << "Score: " << score << endl;
    }

    bool alive() const { return isAlive; }
};

int main() {
    Snake snake;
    while (snake.alive()) {
        snake.draw();
        Sleep(100);  // ������Ϸ�ٶ�

        // �����������
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
