

// var b= 'ts'

// var a= 'aaaaaaaaatsaaaaa'


// // let result  =a.match(b)

// // console.log (result?.index)


// let reg = "[\u4e00-\u9fa5]{0,8}";
// var str = "w我爱你asd"
// console.log (str.match(reg))


// // let regg = "^[a-zA-Z0-9]{0,16}"
// // var str = "asdasdasdasdasdasd唉"
// // console.log (str.match(regg))

// // let reggg = "^[a-zA-Z0-9\u4e00-\u9fa5]{0,16}"
// // var str = "w我爱你asd"
// // console.log (str.match(reggg))

// function checkName(psw: string): boolean {
//     let reg = "^[\u4e00-\u9fa5]{0,8}"
//     let regg = "^[a-zA-Z0-9]{0,16}"
//     let reggg = "^[a-zA-Z0-9\u4e00-\u9fa5]{0,16}"
//     let result1 = psw.match(reg)
//     let result2 = psw.match(regg)
//     let result3 = psw.match(reggg)
//     console.log("result1 " + result1?.[0]  );
//     console.log("result2 " + result2?.[0] );
//     console.log("result3 " + result3?.[0] );
//     return false
//   }


  var regggg= /\d+/

  var str ="123123123"

  console.log(str.match(regggg))


  var regggg= /[a-zA-Z0-9]+/

  var reg = /[\u4e00-\u9fa5]+/

  var str ="1231我爱你23123"

  console.log(str.match(regggg))
  console.log(str.match(reg))


  
    // let uint8array = StrUtil.strToUint8Array(str)
    // // latin1   java 按2算   鸿蒙 这边按3算
    // let result = StrUtil.unit8ArrayToStr(uint8array, "latin1")