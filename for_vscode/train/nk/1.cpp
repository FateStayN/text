#include <bits/stdc++.h>
#include <process.h>
#include <windows.h>

const int N = 32;
const int inf = 0x3f3f3f3f;
DWORD waitTime = 10000;
HANDLE m_S_Empty;
HANDLE m_S_Full;
HANDLE m_M_Mutex;

using namespace std;

vector <int> buffer;

DWORD WINAPI Producer(void *tmp)
{
    while (true)
    {
        if (WaitForSingleObject(m_S_Empty, waitTime) == WAIT_OBJECT_0)
        {
            if (WaitForSingleObject(m_M_Mutex, waitTime) == WAIT_OBJECT_0)
            {
                int t = rand() % 90 + 10;
                cout << "product a number:" << t << endl;
                buffer.push_back(t);
                cout << "After the production, the number in the buffer is:";
                for (auto i : buffer) cout << i << " ";
                cout << endl;
                ReleaseMutex(m_M_Mutex);
                ReleaseSemaphore(m_S_Full, 1, nullptr);
            }
        }
        int t = rand() % 900 + 100;
        Sleep(t);
    }

}

DWORD WINAPI Consumer(void *tmp)
{
    while (true)
    {

        if (WaitForSingleObject(m_S_Full, waitTime) == WAIT_OBJECT_0)
        {
            if (WaitForSingleObject(m_M_Mutex, waitTime) == WAIT_OBJECT_0)
            {
                cout << "The number in buffer now is:";
                for (auto i : buffer) cout << i << " ";
                cout << endl;
                int t = buffer.back();
                cout << "So the number we consum now is:" << t << endl;
                buffer.pop_back();
                ReleaseMutex(m_M_Mutex);
                ReleaseSemaphore(m_S_Empty, 1, nullptr);
            }
        }
        int t = rand() % 900 + 100;
        Sleep(t);
    }
}   

int main()
{
    fstream fout;
    fout.open("result.txt", ios::out);
    srand((unsigned)time(nullptr));
    HANDLE producer = CreateThread(nullptr, 0, &Producer, nullptr, 0, nullptr);
    HANDLE consumer = CreateThread(nullptr, 0, &Consumer, nullptr, 0, nullptr);
    m_S_Empty = CreateSemaphore(nullptr, N, N, nullptr);
    m_S_Full = CreateSemaphore(nullptr, 0, N, nullptr);
    m_M_Mutex = CreateMutex(NULL, FALSE, (LPCTSTR)"sample07");
    system("pause");
}

