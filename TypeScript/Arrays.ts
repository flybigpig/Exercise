
let arr5: Array<Array<number>> =  [[1, 2], [3, 4]]

let i= 15 %12  
let n=Math.ceil(15/12)


console.log(i +"  "+ n)

// 锟斤拷锟斤拷锟斤拷录锟斤拷锟截的接口猴拷锟斤拷锟酵讹拷锟斤拷
interface LoginCredentials {
    username: string;
    password: string;
}

interface LoginResponse {
    success: boolean;
    token?: string;
    error?: string;
}

// 锟斤拷录锟斤拷锟斤拷
async function login(credentials: LoginCredentials): Promise<LoginResponse> {
    try {
        // 锟斤拷锟斤拷应锟斤拷锟斤拷实锟绞的碉拷录API锟斤拷锟斤拷
        // 示锟斤拷实锟斤拷
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
            error: error instanceof Error ? error.message : '锟斤拷录失锟斤拷'
        };
    }
}

// 使锟斤拷示锟斤拷
const loginExample = async () => {
    const result = await login({
        username: 'testuser',
        password: 'testpass'
    });

    if (result.success) {
        console.log('锟斤拷录锟缴癸拷:', result.token);
    } else {
        console.error('锟斤拷录失锟斤拷:', result.error);
    }
};
