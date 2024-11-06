
let arr5: Array<Array<number>> =  [[1, 2], [3, 4]]

let i= 15 %12  
let n=Math.ceil(15/12)


console.log(i +"  "+ n)

// // ������¼���صĽӿں����Ͷ���
// interface LoginCredentials {
//     username: string;
//     password: string;
// }

// interface LoginResponse {
//     success: boolean;
//     token?: string;
//     error?: string;
// }

// // ��¼����
// async function login(credentials: LoginCredentials): Promise<LoginResponse> {
//     try {
//         // ����Ӧ����ʵ�ʵĵ�¼API����
//         // ʾ��ʵ��
//         const response = await fetch('/api/login', {
//             method: 'POST',
//             headers: {
//                 'Content-Type': 'application/json'
//             },
//             body: JSON.stringify(credentials)
//         });

//         const data = await response.json();
//         return {
//             success: response.ok,
//             token: data.token,
//             error: !response.ok ? data.error : undefined
//         };
//     } catch (error) {
//         return {
//             success: false,
//             error: error instanceof Error ? error.message : '��¼ʧ��'
//         };
//     }
// }

// // ʹ��ʾ��
// const loginExample = async () => {
//     const result = await login({
//         username: 'testuser',
//         password: 'testpass'
//     });

//     if (result.success) {
//         console.log('��¼�ɹ�:', result.token);
//     } else {
//         console.error('��¼ʧ��:', result.error);
//     }
// };
