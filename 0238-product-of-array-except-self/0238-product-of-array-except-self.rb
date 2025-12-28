# @param {Integer[]} nums
# @return {Integer[]}
def product_except_self(nums)
    prod = 1
    n = nums.length
    pre = Array.new(n,1)
    suf = Array.new(n,1)
    for i in 1...n
        pre[i] = pre[i-1]*nums[i-1]
        suf[n-i-1] = suf[n-i]*nums[n-i]
    end

    res = []

    for i in 0...n
        res << pre[i] * suf[i]
    end

    return res    
end