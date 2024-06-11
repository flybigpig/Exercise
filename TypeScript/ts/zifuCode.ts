var str = "aaaa我"; // 假设这是包含中文字符的字符串
const uint8array = new TextEncoder().encode(str);
const newString = new TextDecoder("ISO-8859-1").decode(uint8array);
console.log(newString);

