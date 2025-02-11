class Shape {
  Area: number;

  constructor(a: number) {
    this.Area = a;
  }
}

class Circle extends Shape {
  disp(): void {
    console.log("圆的面积:  " + this.Area);
  }
}

var o = new Circle(2.253);
o.disp();
