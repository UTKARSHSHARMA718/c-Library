#define ll long long
#define prime 31
#define MOD 1000000007

// NOTES:
// prime taken as 31 becuase the avaialable range of values are 1 to 26 (a to z)
// if the range would be 52 then we would have to take a prime number greater than 52
// since we always try to take prime number greater than the range in-order to avoid collision chances.

int sz(string& a)
{
    return static_cast<int>(a.size());
}

void rollingHash(vector<int>& vec, string &s, string a)
{
    ll hashValue = 0;
    ll multiplier = prime;
    ll inverse = modInverse(prime , MOD);
    for(int i=0; i<sz(a); i++)
    {
        ll v = ((a[i] - 'a' + 1) * multiplier * 1LL) % MOD;
        multiplier = (multiplier * prime * 1LL) % MOD;
        hashValue += v % MOD;
        hashValue %= MOD;
    }
    multiplier = prime;
    ll sV = 0;
    for(int i=0; i<sz(a)-1 && i < sz(s); i++)
    {
        sV += ((s[i] - 'a' + 1) * multiplier * 1LL) % MOD;
        sV %= MOD;
        multiplier = (multiplier * prime * 1LL) % MOD;
        
    }
    for(int i=sz(a)-1; i<sz(s); i++)
    {
        //add
        sV += ((s[i] - 'a' + 1) * multiplier * 1LL) % MOD;
        sV %= MOD;
        if(sV == hashValue)
        {
            vec.emplace_back(i-sz(a)+1);
        }
        //remove
        sV = (sV - ((s[i-sz(a)+1]-'a'+1) * prime * 1LL)) % MOD;
        sV = sV * inverse; // dividing by prime (31)
    }
}
