
let arr5: Array<Array<number>> =  [[1, 2], [3, 4]]

let i= 15 %12  
let n=Math.ceil(15/12)


console.log(i +"  "+ n)

// 创建登录相关的接口和类型定义
interface LoginCredentials {
    username: string;
    password: string;
}

interface LoginResponse {
    success: boolean;
    token?: string;
    error?: string;
}

// 登录函数
async function login(credentials: LoginCredentials): Promise<LoginResponse> {
    try {
        // 这里应该是实际的登录API调用
        // 示例实现
        const response = await fetch('/api/login', {
            method: 'POST',
            headers: {
                'Content-Type': 'application/json'
            },
            body: JSON.stringify(credentials)
        });

        const data = await response.json();
        return {
            success: response.ok,
            token: data.token,
            error: !response.ok ? data.error : undefined
        };
    } catch (error) {
        return {
            success: false,
            error: error instanceof Error ? error.message : '登录失败'
        };
    }
}

// 使用示例
const loginExample = async () => {
    const result = await login({
        username: 'testuser',
        password: 'testpass'
    });

    if (result.success) {
        console.log('登录成功:', result.token);
    } else {
        console.error('登录失败:', result.error);
    }
};
