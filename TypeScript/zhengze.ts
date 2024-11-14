var s="99.66%百万"

 console.log(s.replace(/[^\.\d]/g,""))


 console.log(s.replace(/[\u4e00-\u9fa5]+/g, ""))


 var reg =/[\u4e00-\u9fa5]+/g

 console.log(s.match(reg)?.[0].toString())

const chineseText = "这是一段中文文本。";
const regex = /[\u4e00-\u9fa5]/g;

const chineseCharacters = chineseText.match(regex);

console.log(chineseCharacters); // ["这", "是", "一", "段", "中", "文", "文", "本"]


const chineseText1 = "这是一段中文文本。";
const regex2 = /[\u4e00-\u9fa5]+/g;

const chineseWords = chineseText1.match(regex2);

console.log(chineseWords); // ["这是一段中文文本"]