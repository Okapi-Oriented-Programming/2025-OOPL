# Abstract

遊戲名稱：要塞守護

組員：

- 112820003 辛政隆
- 112820025 陳翊揚

# Game Introduction

- 一款2D的塔防遊戲，在路線旁的空格上可以建造角色去抵禦從敵人巢穴出來的各種怪物。
- 利用打敗怪物後獲得的金幣，去建造新的或是升級舊有的角色。
- 其中怪物走的路線會隨著難度提升而不只一種，玩家須善用怪物走的路線、角色特性、升級角色去抵禦怪物，例如：轉角適合放範圍攻擊的。
- 生成的怪物也會依據難度有不同的特性，例如：快速奔跑的野狼、血量多的巨人等等。
- 整體類似於
[影片範例](https://youtu.be/EhZvFySWthI?si=6EFd8ik-wV1OvLYg&t=383)
中的玩法
# Development timeline

- Week 1：準備素材
  - [ ] 蒐集遊戲的素材
  - [ ] 搜尋、下載或自製可能使用的圖像、音效素材（地圖背景、角色、怪物、UI 等）

- Week 2：處理遊戲的封面、關係圖
  - [ ] 進行遊戲封面的設計
  - [ ] 擬定好類別的關係圖
  - [ ] 玩法、流程圖確定

> **產出**：初步的素材庫、類別設計草圖（UML）、首頁UI介面


- Week 3 ～ Week 4：基礎專案架構
  - [ ] 撰寫最簡單的程式骨架：`main`、`GameLoop`、`SceneManager` 或者使用簡易的 state machine：`Start`、`Update`。
  - [ ] 實作遊戲封面（主選單）：包含開始遊戲、離開遊戲等按鈕。
  - [ ] 實作關卡選單（即使目前只有 1～2 關，也先確立框架）。
  - [ ] 連結流程：點擊「開始遊戲」後可進入關卡選擇 → 進入遊戲主場景。

> **產出**：能進入並切換「封面 → 關卡選單 → 空白遊戲場景」的骨架程式

- Week 5 ～ Week 7：地圖與路線系統、設計`Enemy`
- [ ] 建立 `Map` 類別，包含地圖大小、可建造區塊、敵人出現位置與終點位置。
- [ ] 規劃並可視化地圖(可先用簡單方塊表示)。
- [ ] 實作敵人移動的路徑（waypoints）或使用座標陣列，讓敵人能自動從起點走到終點。
- [ ] 支援多條路線：如果想增加難度，可考慮讓怪物有不同進攻路徑。
- [ ] 在地圖上標示或儲存可以放置角色的位置，並且呈現在畫面上。
- [ ] 設計 `Enemy` 父類別：包含血量、移動速度、給予玩家金幣獎勵等。
- [ ] 先設計最普通的怪物並成功使他行走在規劃的路線上
- [ ] 敵人血量歸零 → 播放死亡效果 → 發放玩家金幣。
- [ ] 若敵人成功走到終點 → 扣玩家生命值或分數；生命值歸零判定遊戲失敗。

> **產出**：遊戲中能夠顯示地圖、並且有敵人移動路徑的基礎

- Week 8 ～ Week 10：角色`Charter`設計 & 攻擊邏輯
- [ ] 設計 `Charter` 父類別，定義屬性：攻擊力、射程、攻速、費用等。
- [ ] 規劃子類別（如：戰士、弓箭手、魔法師等等），在屬性與攻擊機制上有所不同。
- [ ] 在可建造區域放置角色：檢查玩家金幣是否足夠。
- [ ] 針對已放置的角色，實作升級功能（花費金幣提高攻擊力或攻速）。
- **攻擊機制**
  - [ ] 判斷角色在**固定冷卻時間**後，是否有敵人在射程內；若有則發射子彈或直接扣血。
  - [ ] 選擇實作方式：
    - A. **投射物**(如弓箭手)：建立類似 `Projectile`/`Bullet` 類別，子彈飛行與碰撞判定。
    - B. **即時傷害**(如戰士)：省略子彈飛行，直接在塔內部計算敵人受傷害。
> **產出**：能在遊戲中放置角色，並對路徑上的敵人造成傷害的基礎功能

> **期中展示以上內容**

- Week 11 ～ Week 12：怪物（Enemy）與波數（Wave）系統
- [ ] 規劃子類別：
  - 快速的野狼（移動快、血量低）
  - 血量高的巨人（移動慢、血量厚）
  - 或其他特殊攻擊型怪物
- [ ] `WaveManager` or `GameController` 中的波數系統：一波波產生敵人，間隔幾秒一隻或一次多隻。
- [ ] 設定不同波數的敵人種類、數量、出怪頻率。
- [ ] 追蹤並顯示目前是第幾波，波與波之間可給玩家準備或升級時間。


> **產出**：多波怪物進攻的遊戲節奏，能夠測試敵人種類與難度

- Week 15 ~ Week 16：製作後續地圖
- [ ] 完成後續2 ~ 15關的地圖或關卡（如難度上升或地形變化）。
- [ ] 更多怪物類型（會分裂、範圍攻擊）或更多角色類型(增益的法師或群攻的炸彈客之類的)。
- [ ] 加入教程或提示（例如在第一波前提醒如何建造塔）。

> **產出**：可以在第一關完成之後，可以接續玩後面的關卡




- Week 17：難度調整 & 測試修正
  - [ ] 調整各種角色的攻擊力、費用、升級效果，避免過強或過弱。
  - [ ] 調整怪物血量、速度、波數配置，讓遊戲有適度挑戰且不至於不可能通關。

  - [ ] 進行多次關卡測試，嘗試不同策略（塔配置、升級順序）來檢驗遊戲體驗。
  - [ ] 收集 Bug 或不合理處，並修正程式邏輯或數值。

  - [ ] 檢查遊戲更新迴圈、物件釋放（記憶體洩漏）等問題。
  - [ ] 從主選單到遊戲通關或失敗，再回到選單，全流程自測及組內互測。
  - [ ] 檢查所有 UI 與字體、素材連結是否完整。
  - [ ] 製作簡報或文件，說明整體程式設計理念、OOP 架構、流程圖等。
  - [ ] 準備演示影片或實機 Demo，展示核心玩法與特色。
  - [ ] 記錄開發中學到的程式技巧、團隊合作經驗、未來改進方向。

> **產出**：更完善且平衡的遊戲體驗，並減少主要 Bug

- Week 18：最終整合 & 期末前完成報告

> **產出**：可公開或上傳的最終遊戲版本、完整的報告或簡報

