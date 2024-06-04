

var url = "https://mobilekh.yto.net.cn/#/helpCenter?token=BearereyJhbGciOiJIUzUxMiJ9.eyJzdWIiOiJhM2Y4MmQ0YWI4NjE0MzAzYTlkYzI4ZjU0N2JhNDNiNCIsImNyZWF0ZWQiOjE3MTc0Nzc2Mzk2NDcsImV4cCI6MTcyMDA2OTYzOX0.Up4Ix4z4BzvCIwhJHhWyvs9uKOGIXf8X7JekbjDwjnVu_xSvRiKJLiFJGvsI4zka0hG28UIZFQDnxGppnOrbBA&userCode=a3f82d4ab8614303a9dc28f547ba43b4&version=73.2.0.1"

function urlQueryToArr( url :string) {
    const arr = url.split('?')[1].split('&');
   return arr
}

console.log(JSON.stringify(urlQueryToArr(url)))