# Cocos2dxPortfolio

에픽세븐을 소재로 만든 Cocos2d-x 4 / C++17 오프라인 4인 턴제 전투 프로토타입입니다. 개인 학습 프로젝트이며 판매하거나 배포하지 않습니다.

전투 규칙을 렌더러와 분리하고, 결과를 이벤트로 받아 연출합니다. 로비, 지도, 스테이지, 편성, 전투, 결과로 이어지는 흐름을 Windows와 Android에서 실행했습니다.

## 구성

| 코드 | 내용 |
|---|---|
| `Classes/core` | 렌더러와 무관한 전투 규칙, 스킬 시간표 시계 |
| `GameScene`, `BattleHud` | 전투 입력, 행동 연출, HUD |
| `SkillPresentation` | 시간표 데이터로 카메라, 이펙트, 컷인을 합성 |
| `SpinePreview`, `LegacySpinePose`, `WebpAnimation` | Spine 렌더링과 구버전 포즈 호환, WebP 재생 |
| `FrontendScene` | 전투 밖 메뉴 흐름 |
| `SaveStore` | 저장과 구버전 데이터 이전 |
| `ReferenceAudio` | 오디오 재생 관리 |

## 참고

- 소스 코드만 공개합니다. 리소스, 데이터 도구, 테스트, 갤러리 화면은 포함하지 않아 이 저장소만으로는 빌드되지 않습니다.
