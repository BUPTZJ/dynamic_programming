for(int i=1;i<=m;i++){
    if(p[i]*c[i]>=n){//��������V��������ȫ���� 
        for(int j=p[i];j<=maxv;j++){
            dp[j]=max(dp[j-p[i]]+h[i],dp[j]);
        }
    }
    else{//�����Ʋ����01���� 
        int k, ki;
        for(k = 0; ((1 << (k + 1)) - 1) < c[i]; ++k){
            ki = (1 << k);
            for(int j=maxv;j>=p[i]*ki;j--){
                dp[j] = max(dp[j - p[i] * ki] + h[i] * ki, dp[j]);
            }
        }
        ki = c[i] - ((1 << k) - 1);
        for(int j=maxv;j>=p[i]*ki;j--){
            dp[j] = max(dp[j - p[i] * ki] + h[i] * ki, dp[j]);
        }
    }
}
