import { Injectable } from '@angular/core';

import { Keyword } from './keyword';
import { KEYWORDS } from './mock-keyword';


@Injectable()
export class KeywordService {

  getHeroes(): Keyword[] {
    return KEYWORDS;
  }

}
