Fetch API 是一种现代的 JavaScript API，用于发起网络请求，取代了旧的 `XMLHttpRequest`。它提供了更简洁、更强大的方式来处理网络请求和响应。

### 基本使用

以下是一个使用 Fetch API 获取 JSON 数据的基本示例：

```javascript
fetch('https://api.example.com/data')
  .then(response => {
    if (!response.ok) {
      throw new Error('网络响应不正常');
    }
    return response.json();
  })
  .then(data => {
    console.log(data);
  })
  .catch(error => {
    console.error('发生错误:', error);
  });

```

在这个示例中：

1. `fetch` 函数用于发起一个 GET 请求到指定的 URL。
2. `then` 方法处理响应，首先检查响应状态是否正常（`response.ok`），如果不正常则抛出错误。
3. `response.json()` 方法将响应体解析为 JSON 格式。
4. 第二个 `then` 方法处理解析后的数据。
5. `catch` 方法捕获并处理可能出现的错误。

### 发送 POST 请求

你还可以使用 Fetch API 发送 POST 请求并携带数据：

```javascript
const data = {
  name: 'John Doe',
  age: 30
};

fetch('https://api.example.com/submit', {
  method: 'POST',
  headers: {
    'Content-Type': 'application/json'
  },
  body: JSON.stringify(data)
})
  .then(response => {
    if (!response.ok) {
      throw new Error('网络响应不正常');
    }
    return response.json();
  })
  .then(result => {
    console.log(result);
  })
  .catch(error => {
    console.error('发生错误:', error);
  });

```

在这个示例中：

1. `method` 属性指定请求方法为 POST。
2. `headers` 属性设置请求头，指定请求体的内容类型为 JSON。
3. `body` 属性将数据对象转换为 JSON 字符串并发送。

### 兼容性

Fetch API 在现代浏览器中得到了广泛支持，但在一些旧浏览器中可能不支持。你可以使用 `whatwg-fetch` 这样的 polyfill 来解决兼容性问题。

通过 Fetch API，你可以方便地处理各种类型的网络请求，包括 GET、POST、PUT、DELETE 等，并且可以轻松地处理响应数据。
