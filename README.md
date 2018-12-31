# 이중 연결 리스트
## 📢 개요

 이중 연결 리스트(Doubly Linked List)는 `다음 노드(Next Node)`가 **일방적**으로 `이전 노드(Previous Node)`를 연결하고 있던 단일 연결 리스트(단일 연결 리스트)와 달리 `이전 노드(Previous Node)`와 `다음 노드(Next Node)`가 **서로 연결**되어 있는 연결 리스트이다.
 
 그래서 단일 연결 리스트에 비해 구현이 조금 까다롭고 다음 노드와 이전 노드를 가리키는 포인터가 두 개 필요하여 메모리를 더 사용한다는 단점이 있다. 하지만, 탐색이 양방향에서 가능하다는 큰 이점이 있다.
 
 
  ![Program](https://s3.ap-northeast-2.amazonaws.com/opentutorials-user-file/module/1335/2949.png)

 **figure 1. Doubly Linked List*
 

 
 ## 🅿 원리
 ### 1. 노드 추가
   단순 연결 리스트와 거의 비슷합니다. 중요한 차이점은 양방향으로 연결을 해야 한다는 점입니다. 새로운 노드(25)를 기존의 노드(20, 30)와 연결하는 방법만 살펴보겠습니다.

  ![](https://s3.ap-northeast-2.amazonaws.com/opentutorials-user-file/module/1335/2958.png)

 **figure 2. Phase 1*

  25의 다음 노드로 30을 연결합니다.

  ![](https://s3.ap-northeast-2.amazonaws.com/opentutorials-user-file/module/1335/2959.png)

 **figure 3. Phase 2*

  30의 이전 노드로 25를 연결합니다.

  ![](https://s3.ap-northeast-2.amazonaws.com/opentutorials-user-file/module/1335/2960.png)

 **figure 4. Phase 3*

  20의 다음 노드로 25를 지정합니다.

  ![](https://s3.ap-northeast-2.amazonaws.com/opentutorials-user-file/module/1335/2961.png)

 **figure 5. Phase 4*

  25의 이전 노드로 20을 지정합니다.

  ![](https://s3.ap-northeast-2.amazonaws.com/opentutorials-user-file/module/1335/2962.png)

 **figure 6. Phase 5*

  노드의 추가가 끝났습니다.

  ![](https://s3.ap-northeast-2.amazonaws.com/opentutorials-user-file/module/1335/2963.png)

 **figure 7. Phase 6*
 
 #### ● 소스 코드
      void DoublyLinkedlist::push_front(char* szData)
      {
        stNODE *pNode = (stNODE*)malloc(sizeof(stNODE));

        memcpy(pNode->szData, szData, sizeof(pNode->szData));

        pNode->pPrev = &_Head;
        pNode->pNext = _Head.pNext;
        pNode->pPrev->pNext = pNode;
        pNode->pNext->pPrev = pNode;
      }

      void DoublyLinkedlist::push_back(char* szData)
      {
        stNODE *pNode = (stNODE*)malloc(sizeof(stNODE));

        memcpy(pNode->szData, szData, sizeof(pNode->szData));

        pNode->pPrev = _Tail.pPrev;
        pNode->pNext = &_Tail;
        pNode->pPrev->pNext = pNode;
        pNode->pNext->pPrev = pNode;
      }
 
 ### 2. 노드 제거
 
  ![](https://s3.ap-northeast-2.amazonaws.com/opentutorials-user-file/module/1335/2969.png)

 **figure 8. Phase 1*

  삭제하려는 노드의 이전 노드(20)을 찾습니다.
  
  ![](https://s3.ap-northeast-2.amazonaws.com/opentutorials-user-file/module/1335/2970.png)

 **figure 9. Phase 2*
  
  삭제하려는 노드(30)도 찾습니다.

  ![](https://s3.ap-northeast-2.amazonaws.com/opentutorials-user-file/module/1335/2971.png)

 **figure 10. Phase 3*

  삭제하려는 노드의 다음 노드(40)도 찾습니다.

  ![](https://s3.ap-northeast-2.amazonaws.com/opentutorials-user-file/module/1335/2972.png)

 **figure 11. Phase 4*

  30을 삭제합니다.

  ![](https://s3.ap-northeast-2.amazonaws.com/opentutorials-user-file/module/1335/2973.png)

 **figure 12. Phase 5*

  20의 다음 노드로 40을 지정합니다.

  ![](https://s3.ap-northeast-2.amazonaws.com/opentutorials-user-file/module/1335/2974.png)

 **figure 13. Phase 6*

  40의 이전 노드로 20을 지정합니다.

  ![](https://s3.ap-northeast-2.amazonaws.com/opentutorials-user-file/module/1335/2975.png)

 **figure 14. Phase 7*

  삭제가 완료 되었습니다.
 
 
  #### ● 소스 코드
      bool DoublyLinkedlist::Delete(char* szData)
      {
        stNODE *pNode = _Head.pNext;

        while (pNode->pNext != NULL)
        {
          if (strcmp(pNode->szData, szData) == 0)
          {
            pNode->pPrev->pNext = pNode->pNext;
            pNode->pNext->pPrev = pNode->pPrev;
            free(pNode);
            return true;
          }
          pNode = pNode->pNext;
        }
        return false;
      }
 
 
 ## 📌 이미지 및 설명 출처 
 
 https://opentutorials.org/module/1335/8940



