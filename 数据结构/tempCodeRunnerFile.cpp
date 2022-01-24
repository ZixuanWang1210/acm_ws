s::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>b[i];
    q.push(node(a[1],b[1]));

    for(int i=1;i<=n;i++){
        // int x=q.top().x,y=q.top().y;
        while(mp[make_pair(q.top().x,q.top().y)]) q.pop();
        int x=q.top().x,y=q.top().y;
        int sum=x+y; cout<<sum<<" ";
        mp[make_pair(x,y)]=1;
        q.push({x+1,y});q.push({x,y+1});
    }
    
    