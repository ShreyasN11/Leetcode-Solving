# @param {Integer[]} prices
# @return {Integer}
def max_profit(prices)
    profit = 0
    mini = prices[0]
    n = prices.length
    for i in 1...n 
        mini = mini > prices[i] ? prices[i] : mini
        profit = profit > prices[i] - mini ? profit : prices[i] - mini
    end       
    return profit
end