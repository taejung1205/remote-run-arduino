# remote-run-arduino
아두이노의 초음파센서를 활용해 직접 만지지 않고 조종하는 러닝 게임입니다. 

작품설명
 초음파 거리 센서를 활용하여, 단말기 접촉 없이 조작하여 플레이하는 유니티 게임입니다. 컨트롤러 박스 양옆에 붙은 두 개의 초음파 센서를 활용하여, 양손이 각각 센서와 두는 거리를 바탕으로 캐릭터를 조작하여 장애물을 피해 목표 지점까지 도달하는 것이 게임의 클리어 목표입니다. 
게임을 시작하기 위해선 첫 화면에서 보여주는 이미지대로 양손을 컨트롤러 옆에 두어야 합니다. 양손이 센서에 인식되면 게임이 시작됩니다. 두 센서가 각각 인식하는 거리를 바탕으로, 손이 컨트롤러에서 더 멀리 떨어진 방향으로 게임 캐릭터가 이동하며, 벽 또는 장애물에 닿을 경우 게임 오버가 되어 첫 시작으로 돌아옵니다. 약 1분동안 충돌 없이 플레이하면 최종 목적지에 도달할 수 있으며, 게임을 클리어했다는 메시지와 함께 처음으로 되돌아옵니다. 
빌드된 상태로 과제전 등 외부 환경에서 플레이가 가능하게 하기 위해, 설정 메뉴를 추가하여 PORT값과 센서 민감도를 설정할 수 있게 만들었습니다. (MacOS 기준) 터미널에서 “ls /dev/tty.*”를 입력해 현재 아두이노 장치가 연결된 포트를 확인할 수 있으며, 이를 PORT 설정에 입력해 게임이 아두이노 장치를 인식할 수 있게 만들어야 합니다. 센서 민감도의 경우, 이 값이 높을수록 캐릭터가 좌우로 더 많이 이동하므로 사용 환경에 따라 적절하게 수정하는 것이 좋습니다. 

사용부품
	아두이노 우노 보드 (키트 내장)		x1
	전원 및 통신 케이블 (키트 내장)		x1
	미니 브레드보드 DM331		x1
	초음파 거리 센서 HC-SR04 DM453	x2
	점퍼 와이어 M-F (키트 내장)		x8
	점퍼 와이어 M-M (키트 내장)		x2
	기타 고정용 도구
