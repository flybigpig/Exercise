console.log("hello  world");

const hello : string = "Hello World!"
console.log(hello)

let binaryLiteral: number = 0b1010; // 二进制
let octalLiteral: number = 0o744;    // 八进制
let decLiteral: number = 6;    // 十进制
let hexLiteral: number = 0xf00d;    // 十六进制


// 在元素类型后面加上[]
let arr1: number[] = [1, 2];

// 或者使用数组泛型
let arr2: Array<number> = [1, 2];


/**
 * 元组类型用来表示已知元素数量和类型的数组，各元素的类型不必相同，对应位置的类型需要相同。
 */
let x: [string, number[],number];
x = ['Runoob', [1, 2],3];    
x.push(5);
console.log(x[x.length-1]);    

let y: any = 4;
y.toFixed();    // 正确



