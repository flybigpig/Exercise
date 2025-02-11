# 定义一个形状类
class Shape:
    def __init__(self, area):
        self.area = area

# 定义一个圆形类，继承自形状类
class Circle(Shape):
    def display(self):
        print(f"圆的面积: {self.area}")

# 创建一个圆形对象并显示面积
circle = Circle(2.253)

circle.display()
