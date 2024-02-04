//literal type 지정
//아래 변수에는 EUNGCHAN만 들어올 수 있음
let kane : 'EUNGCHAN' | 'KANGEUNGCHAN';
type RPS_TYPE = ['ROCK' | 'PAPER' | 'SCISSOR'];

//kane, kang만 입력받고 1, 0만 리턴해주는 함수 만들기
function func4(arg : 'KANE' | 'KANG') : 1 | 0 {
    return 1;
}
//함수 argument, return value도 literal type을 정할 수 있음
// literal type은 문자열처럼 보이지만 실제 type이다. 즉 type이 'ROCK'
function rps(arg : 'ROCK' | 'PAPER' | 'SCISSOR') : ('ROCK' | 'PAPER' | 'SCISSOR')[] {
    if (arg == 'PAPER') {
        return ['PAPER'];
    }
    return ['PAPER'];
}

var DATA = {
    name : 'ROCK',
} as const

//DATA.name은 type이 string인데 rps에서 요구하는 것은 'ROCK' .. type이므로 안됨
//이 경우 data type에 const 붙이면 됨(readonly로 정하면서 literal type으로 사용하고 싶을 때 이거 씀)
rps(DATA.name);