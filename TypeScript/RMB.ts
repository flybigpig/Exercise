// 复制代码
/**
 * 格式化人民币金额
 * @param number num 数字金额
 * @param string symbol 金额符号，默认值为人民币："CNY" 
 * @example symbol符号参数如下：
 * 'USD' 表示使用美元作为货币单位
 * 'EUR' 表示使用欧元作为货币单位
 * 'JPY' 表示使用日元作为货币单位
 * 'GBP' 表示使用英镑作为货币单位
 * 'AUD' 表示使用澳元作为货币单位
 * 'CAD' 表示使用加元作为货币单位
 * 'CHF' 表示使用瑞士法郎作为货币单位
 * 'HKD' 表示使用港币作为货币单位
 * 'NZD' 表示使用新西兰元作为货币单位
 * @returns 格式化后的人民币金额
 * @example 示例如下：
 * formatAmount(290,"CNY")  //输出 ￥290.00
 */
export const formatAmount = (num: number | string, symbol?: string) => {
    return num ? num.toLocaleString('zh', { style: 'currency', currency: symbol || 'CNY' }) : num
}

export const formatAmounts = (num: number ) => {
    return num ? num.toLocaleString('zh', { style: 'currency', currency:  'CNY' }) : "￥"+ num
}

let res =formatAmount(0.00,"CNY")  // 输出 US$9.15
//  res =formatAmounts(0)  // 输出 US$9.15
console.log(res)

let ress =formatAmount(0.00,"USD")  // 输出 US$9.15
 ress =formatAmounts(0)
 console.log(ress)



 