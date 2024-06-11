

var url = "https://mobilekh.yto.net.cn/#/helpCenter?token=BearereyJhbGciOiJIUzUxMiJ9.eyJzdWIiOiJhM2Y4MmQ0YWI4NjE0MzAzYTlkYzI4ZjU0N2JhNDNiNCIsImNyZWF0ZWQiOjE3MTc0Nzc2Mzk2NDcsImV4cCI6MTcyMDA2OTYzOX0.Up4Ix4z4BzvCIwhJHhWyvs9uKOGIXf8X7JekbjDwjnVu_xSvRiKJLiFJGvsI4zka0hG28UIZFQDnxGppnOrbBA&userCode=a3f82d4ab8614303a9dc28f547ba43b4&version=73.2.0.1"


url = "https://mobilekh.yto.net.cn/#/helpCenter?&token=BearereyJhbGciOiJIUzUxMiJ9.eyJzdWIiOiJhM2Y4MmQ0YWI4NjE0MzAzYTlkYzI4ZjU0N2JhNDNiNCIsImNyZWF0ZWQiOjE3MTc0NzkxNzE3OTQsImV4cCI6MTcyMDA3MTE3MX0.GFNsS_G9J981LUZnbYV8daKwSRI3-2lSLsysMu201tOV0w5VMl74Nv49e4B2bEuJ_vPT3X_-uJWONt-gMw74xA&userCode=a3f82d4ab8614303a9dc28f547ba43b4&version=1.0.0"


url = "https://mobilekh.yto.net.cn/#/problemOrder/index?userCode=a3f82d4ab8614303a9dc28f547ba43b4&token=BearereyJhbGciOiJIUzUxMiJ9.eyJzdWIiOiJhM2Y4MmQ0YWI4NjE0MzAzYTlkYzI4ZjU0N2JhNDNiNCIsImNyZWF0ZWQiOjE3MTc0Nzc2Mzk2NDcsImV4cCI6MTcyMDA2OTYzOX0.Up4Ix4z4BzvCIwhJHhWyvs9uKOGIXf8X7JekbjDwjnVu_xSvRiKJLiFJGvsI4zka0hG28UIZFQDnxGppnOrbBA&groupId=2608799&phone=18392391572"

url = "https://mobilekh.yto.net.cn/#/indicatorDescription/index?token=BearereyJhbGciOiJIUzUxMiJ9.eyJzdWIiOiJhM2Y4MmQ0YWI4NjE0MzAzYTlkYzI4ZjU0N2JhNDNiNCIsImNyZWF0ZWQiOjE3MTc0Nzc2Mzk2NDcsImV4cCI6MTcyMDA2OTYzOX0.Up4Ix4z4BzvCIwhJHhWyvs9uKOGIXf8X7JekbjDwjnVu_xSvRiKJLiFJGvsI4zka0hG28UIZFQDnxGppnOrbBA&version=73.2.0.1"
function urlQueryToArr( url :string) {
    const arr = url.split('?')[1].split('&');
   return arr
}

console.log(JSON.stringify(urlQueryToArr(url)))