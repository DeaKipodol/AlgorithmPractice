#include<iostream>
#include<string>
#include<vector>
using namespace std;

int head, tail, quantum, Max = 0;

class Process {
public:
    string processName;
    int jobTime, endjobtime;
    Process() : processName(""), jobTime(0), endjobtime(0) {}
    Process(string name, int time) {
        this->processName = name;
        this->jobTime = time;
    }
    int returnTime() {
        return jobTime;
    }
    int returnEndTime() {
        return endjobtime;
    }
    string toString() {
        return processName;
    }
};

void enqueue(Process array[], Process p) {
    if ((tail + 1) % Max == head) {
        cout << "Error: Queue is full\n"; // �߰��� ���� �޽���
        return;
    }
    array[tail] = p;
    tail = (tail + 1) % Max;
}

Process dequeue(Process array[]) {
    if (head == tail) {
        cout << "Error: Queue is empty\n"; // �߰��� ���� �޽���
        return Process(); // ����: ���� ��Ȳ�� �ڵ鸵
    }
    Process mp = array[head];
    head = (head + 1) % Max;
    return mp;
}

int main() {
    int processNumber = 5, time = 100;

    // ������� �Է��� �ް� �ʱ�ȭ
    cin >> processNumber >> quantum;
    Max = processNumber;
    cout << "processNumber = " << processNumber << endl << "Max = " << Max << endl << quantum << endl << endl;

    Process* myJob = new Process[processNumber];
    for (int i = 0; i < processNumber; i++) {
        string pname; int pntime;
        cin >> pname >> pntime;
        Process p = Process(pname, pntime);
        enqueue(myJob, p);
    }

    // ���μ��� �۾� ���
    Process nowProcess;
    Process* endProcess = new Process[Max];
    int nowjobtime = 0, i = 0;

    // ������ ����
    while (head != tail) {
        nowProcess = dequeue(myJob);
        if (nowProcess.jobTime > quantum) { // ����: >= ���� > ��
            nowProcess.jobTime -= quantum;
            nowjobtime += quantum;
            enqueue(myJob, nowProcess);
            cout << "dequeued head: " << head << " tail: " << tail << endl; // �߰��� ����
        }
        else {
            nowjobtime += nowProcess.jobTime;
            nowProcess.endjobtime = nowjobtime;
            if (i < Max) {
                endProcess[i] = nowProcess;
                ++i;
            }
            else {
                cout << "Error: Process array index out of bound\n"; // �߰��� ���� �޽���
            }
            cout << "���μ��� �Ϸ� head: " << head << " tail: " << tail << endl; // �߰��� ����
        }
    }

    for (int k = 0; k < i; k++) {
        cout << "Process Name: " << endProcess[k].toString() << ", Job Time: " << endProcess[k].returnEndTime() << endl;
    }

    delete[] myJob;
    delete[] endProcess;

    return 0;
}
