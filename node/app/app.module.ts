import { NgModule }      from '@angular/core';
import { BrowserModule } from '@angular/platform-browser';
import { FormsModule }   from '@angular/forms';

import { AppComponent }  from './app.component';
import { KeywordComponent }  from './keywords/keyword.component';

@NgModule({
  imports: [BrowserModule, FormsModule],
  declarations: [
      AppComponent,
      KeywordComponent
  ],
  bootstrap: [
    AppComponent
  ]
})
export class AppModule { }
