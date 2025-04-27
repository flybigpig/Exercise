// main.js
const worker = new Worker('worker.js');
worker.onmessage = function (e) {
    console.log('Received message from worker:', e.data);
};
worker.postMessage('Start working');

// worker.js
self.onmessage = function (e) {
    console.log('Received message:', e.data);
    // 这里可以执行一些耗时操作
    const result = longRunningTask();
    self.postMessage(result);
};
function longRunningTask() {
    // 模拟耗时操作
    let sum = 0;
    for (let i = 0; i < 1000000; i++) {
        sum += i;
    }
    return sum;
}