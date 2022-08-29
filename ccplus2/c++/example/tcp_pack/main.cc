#include<iostream>

#define CHONG_QING_SIX_LOCK_FRAME_MAX_LENGTH        4096
#define CHONG_QING_SIX_LOCK_DATA_HEADER_LENGTH      6

int RecvData()
{
    DWORD recv_len = 0;
    int dataLength = 0;
    int sumDataLength = 0;
    int nRemainSize = 0;
    int lastPos = 0;
    BYTE recvbuf[CHONG_QING_SIX_LOCK_FRAME_MAX_LENGTH], databuf[CHONG_QING_SIX_LOCK_FRAME_MAX_LENGTH];
    char oneFrameData[1024];

    memset(recvbuf, 0, sizeof(recvbuf));        
    memset(databuf, 0, sizeof(databuf));        

    //收到服务端消息
    //接受数据，处理粘包，拆分包
    recv_len = (int)recv(m_Socket, (char *)recvbuf, CHONG_QING_SIX_LOCK_FRAME_MAX_LENGTH, 0);
    if (recv_len > 0)
    {
        memcpy(databuf + lastPos, recvbuf, recv_len);
        lastPos += recv_len;
        //判断消息缓冲区的数据长度大于消息头
        while (lastPos >= CHONG_QING_SIX_LOCK_DATA_HEADER_LENGTH)
        {
            //包头做判断，如果包头错误，收到的数据全部清空
            if (databuf[0] == 0xEF && databuf[1] == 0xEF && databuf[2] == 0xEF && databuf[3] == 0xEF)
            {
                dataLength = MAKEWORD(databuf[4], databuf[5]);
                sumDataLength = CHONG_QING_SIX_LOCK_DATA_HEADER_LENGTH + dataLength + 6;
                //判断消息缓冲区的数据长度大于消息体
                if (lastPos >= sumDataLength)
                {
                    //CRC校验
                    if (CheckSum((byte *)databuf, dataLength + CHONG_QING_SIX_LOCK_DATA_HEADER_LENGTH + 2))
                    {
                        memcpy(oneFrameData, databuf, sumDataLength);
                        //处理数据
                        DealData(oneFrameData);
                        //剩余未处理消息缓冲区数据的长度
                        nRemainSize = lastPos - sumDataLength;
                        //将未处理的数据前移
                        if (nRemainSize > 0)
                        {
                            memcpy(databuf, databuf + (dataLength + CHONG_QING_SIX_LOCK_DATA_HEADER_LENGTH + 6), nRemainSize);
                            lastPos = nRemainSize;
                        }
                    }
                    else
                    {
                        if (nRemainSize > 0)
                        {
                            memcpy(databuf, databuf + sumDataLength, nRemainSize);
                        }

                        lastPos = nRemainSize;
                    }
                }
                else
                {
                    break;
                }
            }
            else      //寻找下一个包头
            {
                BOOL isFind = FALSE;
                int nFindStart = 0;
                for (int k = 1; k < lastPos; k++)
                {
                    if (databuf[k] == 0xEF && databuf[k + 1] == 0xEF && databuf[k + 2] == 0xEF && databuf[k + 3] == 0xEF)
                    {
                        nFindStart = k;
                        isFind = TRUE;
                        break;
                    }
                }
                if (isFind == TRUE)
                {
                    memcpy(databuf, databuf + nFindStart, lastPos - nFindStart);

                    lastPos = lastPos - nFindStart;
                }
                else
                {
                    memset(databuf, 0, sizeof(databuf));
                    lastPos = 0;
                    break;
                }
            }
        }
    }
    return 0;
}

int _tmain(int argc, _TCHAR* argv[])
{


    system("pause");
    return 0;
}