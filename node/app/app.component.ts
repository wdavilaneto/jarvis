import {Component} from '@angular/core';

export class MainMenuItems {
    id: number;
    name: string;
}
;

const MENU_ITENS: MainMenuItems[] = [
    {id: 11, name: 'Corpus'},
    {id: 12, name: 'Keywords'},
    {id: 13, name: 'Stop Words'},
    {id: 14, name: 'N-Gram Stop Terms'},
    {id: 15, name: 'N-Grams Keys'},
    {id: 15, name: 'K-means Graph'}
];

@Component({
    selector: 'my-app',
    template: `
      <h1>{{title}}</h1>
      <h2>Main Corpus</h2>
      <ul class="heroes" >
        <li *ngFor="let item of menuItems"
            [class.selected]="hero === selectedItem"
            (click)="onSelect(item)">
          <!-- each hero goes here -->
          <span class="badge">{{item.id}}</span> {{item.name}}
        </li>
      </ul>

      <div *ngIf="selectedItem">
        <h2>{{selectedItem.name}} details!</h2>
        <div><label>id: </label>{{selectedItem.id}}</div>
        <div>
          <label>name: </label>
          <input [(ngModel)]="selectedItem.name" placeholder="name"/>
        </div>
      </div>
    `,
    styles: [`
      .selected {
        background-color: #CFD8DC !important;
        color: white;
      }
      .heroes {
        margin: 0 0 2em 0;
        list-style-type: none;
        padding: 0;
        width: 15em;
      }
      .heroes li {
        cursor: pointer;
        position: relative;
        left: 0;
        background-color: #EEE;
        margin: .5em;
        padding: .3em 0;
        height: 1.6em;
        border-radius: 4px;
      }
      .heroes li.selected:hover {
        background-color: #BBD8DC !important;
        color: white;
      }
      .heroes li:hover {
        color: #607D8B;
        background-color: #DDD;
        left: .1em;
      }
      .heroes .text {
        position: relative;
        top: -3px;
      }
      .heroes .badge {
        display: inline-block;
        font-size: small;
        color: white;
        padding: 0.8em 0.7em 0 0.7em;
        background-color: #607D8B;
        line-height: 1em;
        position: relative;
        left: -1px;
        top: -4px;
        height: 1.8em;
        margin-right: .8em;
        border-radius: 4px 0 0 4px;
      }
    `]
})

export class AppComponent {
    title = "I'm Ultron!";
    menuItems = MENU_ITENS;
    selectedItem: MainMenuItems;

    onSelect(item: MainMenuItems): void {
        this.selectedItem = item;
    }

}
;
