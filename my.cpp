#include "ThostFtdcMdApi.h"
#include "ThostFtdcTraderApi.h"
#include "ThostFtdcUserApiDataType.h"
#include "ThostFtdcUserApiStruct.h"
#include <memory.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
class QCTPMdSpi : public CThostFtdcMdSpi
{
  public:
    void OnRspUserLogin(CThostFtdcRspUserLoginField *pRspUserLogin, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool blsLast);
    void onRspSubMarketData(CThostFtdcSpecificInstrumentField *pSpecificInstrumet, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool blsLast);
    void onRtnDepthMarketData(CThostFtdcDepthMarketDataField *pDepthMarketData);
};
int main()
{
    CThostFtdcMdApi *pUserApi = CThostFtdcMdApi::CreateFtdcMdApi("1.json", true, true);
    char *BROKERID = (char *)malloc(sizeof(char) * 12);
    char *USERID = (char *)malloc(sizeof(char) * 12);
    char *PASSWORD = (char *)malloc(sizeof(char) * 12);
    CThostFtdcReqUserLoginField req;
    memset(&req, 0, sizeof(req));
    strcpy(req.BrokerID, BROKERID);
    strcpy(req.UserID, USERID);
    strcpy(req.Password, PASSWORD);
    int requestsId = 0;
    int ret = pUserApi->ReqUserLogin(&req, ++requestsId);
    //Subscribe Quotation Data
    char *ppInstrumentID[] = {(char *)"123", (char *)"abs"};
    int ret2 = pUserApi->SubscribeMarketData(ppInstrumentID, 2);
}
void QCTPMdSpi::OnRspUserLogin(CThostFtdcRspUserLoginField *pRspUserLogin, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool blsLast)
{
}
// After receiving the login request successfully, the server validates the BrokerID, UserID and Password, and then return the response via OnRspUserLogin method.Developers can judge whether the login is successful via ErrorID in the second parameter pRspInfo.If ErrorID is 0, the login is successful, otherwise failed.
void QCTPMdSpi::onRspSubMarketData(CThostFtdcSpecificInstrumentField *pSpecificInstrumet, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool blsLast)
{
}

void QCTPMdSpi::onRtnDepthMarketData(CThostFtdcDepthMarketDataField *pDepthMarketData)
{
}
