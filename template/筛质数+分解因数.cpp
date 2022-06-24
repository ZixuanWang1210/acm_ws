void init()
{
    int ct = 0;
    for (int i = 2; i < N; i++)
    {
        if (!vis[i])
        {
            rk[i] = ++ct;
            for (int j = i; j < N; j += i)
            {
                vis[j] = 1;
                fac[j].emplace_back(i);
            }
        }
    }
}