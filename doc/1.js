function tes(){
    
}
function add(a, b) {
    return a + b +1;
}

console.log(add(1, 2));
    

function login(username, password) {
    // Placeholder for actual login logic
    if (username === "admin" && password === "admin") {
        return "Login successful";
    } else {
        return "Login failed";
    }
}


function sort(arr) {
    // 实现冒泡排序算法
    if (!Array.isArray(arr)) {
        throw new Error('Input must be an array');
    }

    const len = arr.length;
    for (let i = 0; i < len - 1; i++) {
        for (let j = 0; j < len - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                // 交换元素
                [arr[j], arr[j + 1]] = [arr[j + 1], arr[j]];
            }
        }
    }
    return arr;
}

// 测试排序函数
console.log(sort([64, 34, 25, 12, 22, 11, 90]));
// 日志打印
console.log("123123")


function createBinaryTree(value) {
    return {
        value: value,
        left: null,
        right: null
    };
}

function insertNode(tree, value) {
    if (!tree) {
        return createBinaryTree(value);
    }

    if (value < tree.value) {
        tree.left = insertNode(tree.left, value);
    } else {
        tree.right = insertNode(tree.right, value);
    }

    return tree;
}

function inorderTraversal(tree) {
    const result = [];
    
    function traverse(node) {
        if (node) {
            traverse(node.left);
            result.push(node.value);
            traverse(node.right);
        }
    }
    
    traverse(tree);
    return result;
}

// 测试二叉树
const tree = createBinaryTree(5);
insertNode(tree, 3);
insertNode(tree, 7);
insertNode(tree, 1);
insertNode(tree, 9);

console.log("中序遍历结果:", inorderTraversal(tree)); // [1, 3, 5, 7, 9]
