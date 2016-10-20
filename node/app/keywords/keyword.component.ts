import { Component } from '@angular/core';

import { Keyword } from './keyword';
import { KeywordService } from './keyword.service';

@Component({
    selector: 'keyword-component',
    template: 'ah!'
})

export class KeywordComponent {
  constructor(private keywordService: KeywordService) { };
  providers: [KeywordService];
  title = 'Tour of Heroes to Ultron Mind !';
  keywords: Keyword[];

  getHeroes() : void {
    this.keywords = this.keywordService.getHeroes();
  }

  ngOnInit(): void {
    this.getHeroes();
  }
}
