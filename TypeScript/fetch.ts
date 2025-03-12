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