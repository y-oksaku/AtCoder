import Foundation
infix operator >>> : MultiplicationPrecedence

class Input {
    var inputs : [String] = [];

    func read() {
        self.inputs = readLine()!.components(separatedBy: " ")
        self.inputs.reverse()
    }

    func pop() -> (String) {
        if self.inputs.count == 0 {
            self.read()
        }
        return self.inputs.popLast()!
    }

    static func >>> (cin : Input, right : inout Int) -> (Input) {
        right = Int(cin.pop())!
        return cin
    }
    static func >>> (cin : Input, right : inout String) -> (Input) {
        right = cin.pop()
        return cin
    }
}
let cin = Input()

var N: Int = 0
cin >>> N

var D = [Int](repeating: 0, count: N)
for i in 0..<N {
    cin >>> D[i]
}

D.sort{$0 < $1}

var ans: Int = 0
var now: Int = 0
for d in D {
    if d > now {
        now = d
        ans += 1
    }
}
print(ans)
