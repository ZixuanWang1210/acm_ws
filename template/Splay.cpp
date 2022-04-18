struct Splay 
{
	int rt, tot, fa[N], ch[N][2], val[N], cnt[N], sz[N];
	//sz[x]：x节点子树的大小；cnt[x]:与x节点权值相同的数的个数；val[x]：x节点的权值 
	inline void init()
	{
		rt=tot=0;
	}
  	inline void maintain(int x) { sz[x] = sz[ch[x][0]] + sz[ch[x][1]] + cnt[x]; }//更新节点x的sz 
  	inline bool get(int x) { return x == ch[fa[x]][1]; }//x是否是其父亲节点的右儿子 
  	inline void clear(int x) {ch[x][0] = ch[x][1] = fa[x] = val[x] = sz[x] = cnt[x] = 0;}//删除节点x 
  	inline void rotate(int x) //把x与其父亲节点交换 
	{
	    int y = fa[x], z = fa[y], chk = get(x);
	    ch[y][chk] = ch[x][chk ^ 1]; //利用性质，进行更改节点 
	    fa[ch[x][chk ^ 1]] = y;
	    ch[x][chk ^ 1] = y;
	    fa[y] = x;
	    fa[x] = z;
	    if (z) ch[z][y == ch[z][1]] = x;
	    maintain(x);maintain(y);//更新节点的值//只有x，y节点的sz发生了变化 
  	}
  	void splay(int x) //把x与根节点交换 
	{
    	for (int f = fa[x]; f = fa[x], f; rotate(x))//双旋操作，保证了均摊复杂度log(n)级别 
      		if (fa[f]) 
			  	rotate(get(x) == get(f) ? f : x);
    	rt = x;
 	}
  	void ins(int x) //插入一个数x 
	{
   		if (!rt) 
		{
	      	val[++tot] = x;cnt[tot]++;
	      	rt = tot;maintain(rt);//新建一个节点(此时树为空) 
	     	return;
    	}
    	int now = rt, f = 0;//now：当前查询到的节点 ，f：cnr的父亲节点 
   		while (1) 
		{
	      	if (val[now] == x) 
			{
		        cnt[now]++;
		        maintain(now);
		        maintain(f);
		        splay(now);
		        break;
      		}
      		f = now;
      		now = ch[now][val[now] < x];//根据BST的性质往下查询 
      		if (!now)//如果平衡树中不存在权值为k的节点，则新建一个节点 
			{
		        val[++tot] = x;cnt[tot]++;
		        fa[tot] = f;
		        ch[f][val[f] < x] = tot;
		        maintain(tot);maintain(f);
		        splay(tot);//每次操作都要splay，保证均摊复杂度能做到logn级别 
		        break;
      		}
    	}
  	}
  	int rk(int x) //查询数x的排名(从小到大) ,只要查到权值等于x的节点，所有小于x的数都在x左子树上。 
	{
	    int res = 0, now = rt;//小于x的数有res个
	    while (1) 
		{
	        if (x < val[now]) now = ch[now][0];//根据BST的性质往下找到x所在的位置 
	        else 
			{
		        res += sz[ch[now][0]];//往右走的时候先累加左子树的数量 
		        if (x == val[now]) 
				{
		          	splay(now);
		          	return res + 1;
		        }
		        res += cnt[now];
		        now = ch[now][1];
	      	}
	    }
    }
  	int kth(int k) //查询第k大的数的权值 
  	{
	    int now = rt;
	    while (1) 
		{
	      	if (ch[now][0] && k <= sz[ch[now][0]]) 
	        	now = ch[now][0];
	        else 
			{
		        k -= cnt[now] + sz[ch[now][0]];
		        if (k <= 0) 
				{
		          splay(now);
		          return val[now];
		        }
		        now = ch[now][1];
	      	}
	    }
  	}
  	//注意！执行前驱后继时要先插入x节点(插入时会自动把他旋转到根节点)，然后进行处理，最后再删除x节点。保证每次处理都在根节点进行处理 
	int pre() //查询根节点的前驱，小于根节点权值，且最大的数 
	{
	    int now = ch[rt][0];
	    while (ch[now][1]) now = ch[now][1];
	    splay(now);
	    return now;
	}
	int nxt()//查询根节点的后继，大于根节点权值，且最小的数 
	{
	    int now = ch[rt][1];
	    while (ch[now][0]) now = ch[now][0];
	    splay(now);
	    return now;
	}
  	void del(int k) //删除k节点 
	{
    	rk(k); //这一步的目的是把k旋转到根节点，方便后续处理以及复杂度保证(每一步操作尽量在根节点进行，即用双旋操作缩短深度在处理，防止退化)
    	if (cnt[rt] > 1) 
		{
	      	cnt[rt]--;
	      	maintain(rt);
	      	return;
    	}
	    if (!ch[rt][0] && !ch[rt][1])//树只剩根节点时，树变为空 
		{
		    clear(rt);
		    rt = 0;
		    return;
	    }
	    if (!ch[rt][0]) //如果左子树为空，则以右子树为根 
		{
	      	int now = rt;
	      	rt = ch[rt][1];
	      	fa[rt] = 0;
	     	clear(now);
	     	return;
	    }
    	if (!ch[rt][1])//如果右子树为空，则以左子树为根 
		{
		    int now = rt;
		    rt = ch[rt][0];
		    fa[rt] = 0;
		    clear(now);
		    return;
    	}
		//左右子树均不为空，则以左子树最大权值 的节点做为根节点 (维持BST的性质)
	    int now = rt;
	    int x = pre();
	    splay(x);
	    fa[ch[now][1]] = x;//把x旋转到根节点后，原来根节点的右儿子还未接到x节点 
	    ch[x][1] = ch[now][1];
	    clear(now);//删除原来的根节点 
	    maintain(rt);
  	}
} tree;