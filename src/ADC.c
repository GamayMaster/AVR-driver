
void ADC_Init(void)
{
    SET_BIT(ADMUX, REFS0);
    SET_BIT(ADCSRA, ADEN);
    SET_BIT(ADCSRA, ADPS2);
    SET_BIT(ADCSRA, ADPS1);
}

word ADC_Read(void)
(
    word val;

    SET_BIT(ADCSRA, ADSC);
    while(IS_CLR_BIT(ADCSRA, ADIF));
    SET_BIT(ADCSRA, ADIF);

    val =  (ADCL);
    val |= (ADCH<<8);
    return val;
)
