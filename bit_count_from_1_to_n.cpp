ll getCount(ll x, ll checkForDivisibility)
    {
        ll m = 1;
        ll tot = 0;

        while(x > 0)
        {
            m=1;
            while (m <= x)
            {
                m = m << 1;
            }

            m = m >> 1;

            int msb = (int)(log(m) / log(2));
            
            for (int i = msb; i > 0; i--)
            {
                if (i % checkForDivisibility == 0) // question specific
                {
                    tot += m / 2;
                }
            }

            if ((msb + 1) % checkForDivisibility == 0) // question specific
            {
                  tot += (x - m) + 1;
            }
            
            x = x - m;
            
        }

        return tot;
    }
    
